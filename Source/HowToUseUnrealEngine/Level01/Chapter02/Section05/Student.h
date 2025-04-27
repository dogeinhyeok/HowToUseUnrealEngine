#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Person.h"
#include "Student.generated.h"


UCLASS( ClassGroup=(HowToUseUnrealEngine), meta=(BlueprintSpawnableComponent) )
class HOWTOUSEUNREALENGINE_API UStudent : public UPerson
{
	GENERATED_BODY()

public:
	UStudent();

	virtual void DoLesson() override;

private:
	UPROPERTY()
	int32 StudentNumber;
};
