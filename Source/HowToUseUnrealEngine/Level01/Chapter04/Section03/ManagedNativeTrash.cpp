#include "ManagedNativeTrash.h"
#include "Trash.h"

void FManagedNativeTrash::AddReferencedObjects(FReferenceCollector& Collector)
{
	if (SafeTrash->IsValidLowLevel())
	{
		Collector.AddReferencedObject(SafeTrash);
	}
}