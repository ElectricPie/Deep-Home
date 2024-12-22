// Fill out your copyright notice in the Description page of Project Settings.


#include "Houses/HousingSubsystem.h"
#include "Houses/HouseComponent.h"
#include "Houses/HouseResidentComponent.h"

void UHousingSubsystem::UpdateHouseCapacity(UHouseComponent* House, const uint32 AvailableCapacity)
{
	if (House == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("UHousingSubsystem::UpdateHouseCapacity: House is null"));
		return;
	}

	// Start tracking if not tracking already
	if (!AvailableHouses.Contains(House) && !UnavailableHouses.Contains(House))
	{
		if (AvailableCapacity == 0)
		{
			UnavailableHouses.Add(House);
			return;
		}

		// Assign dwarf to space;
		if (!ResidentsWaitingForHouse.IsEmpty())
		{
			UHouseResidentComponent* Resident = ResidentsWaitingForHouse.Peek()->Get();
			if (House->AddResident(Resident))
			{
				ResidentsWaitingForHouse.Pop();
			}
			
			// Check if there is still space after attempting to add dwarfs
			if (House->GetCurrentCapacity() == 0)
			{
				UnavailableHouses.Add(House);
				return;
			}
		}
		
		AvailableHouses.Add(House);
		return;
	}

	if (AvailableCapacity == 0)
	{
		// Move to unavailable if no capacity
		AvailableHouses.Remove(House);
		UnavailableHouses.Add(House);
	}
	else if (AvailableCapacity > 0)
	{
		// Only update unavailable if their capacity increases 
		UnavailableHouses.Remove(House);
		
		// Assign dwarf to space
		if (!ResidentsWaitingForHouse.IsEmpty())
		{
			UHouseResidentComponent* Resident = ResidentsWaitingForHouse.Peek()->Get();
			if (House->AddResident(Resident))
			{
				ResidentsWaitingForHouse.Pop();
			}
			
			// Check if there is still space after attempting to add dwarfs
			if (House->GetCurrentCapacity() == 0)
			{
				return;
			}
		}
		AvailableHouses.Add(House);
	}
}

void UHousingSubsystem::RequestHouse(UHouseResidentComponent* Resident)
{
	if (Resident == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("UHousingSubsystem::RequestHouse: Dwarf is null"));
		return;
	}

	if (AvailableHouses.Num() > 0)
	{
		for (const auto& House : AvailableHouses)
		{
			// Assign House
			if (House->AddResident(Resident))
			{
				// Successfully assigned house
				return;
			}
		}
	}

	ResidentsWaitingForHouse.Enqueue(Resident);

	UE_LOG(LogTemp, Warning, TEXT("No House available")); 
}
