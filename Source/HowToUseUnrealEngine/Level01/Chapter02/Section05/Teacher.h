#pragma once

#include "CoreMinimal.h"
#include "Person.h"
#include "Teacher.generated.h"


UCLASS( ClassGroup=(HowToUseUnrealEngine) )
class HOWTOUSEUNREALENGINE_API UTeacher : public UPerson
{
	GENERATED_BODY()

public:
	UTeacher();

	virtual void DoLesson() override;

private:
	UPROPERTY()
	int32 TeacherNumber;
};
