#include "Cluster.h"
#include <windows.h>
#include <stdio.h>
#include <time.h>  // For formatting date properites

#pragma comment(lib, "comsupp.lib")

// The Microsoft.Hpc.Scheduler.tlb and Microsoft.Hpc.Scheduler.Properties.tlb type
// libraries are included in the Microsoft HPC Pack 2008 SDK. The type libraries are
// located in the "Microsoft HPC Pack 2008 SDK\Lib\i386" or \amd64 folder. Include the rename 
// attributes to avoid name collisions.
/*#import <Microsoft.Hpc.Scheduler.tlb> named_guids no_namespace raw_interfaces_only \
    rename("SetEnvironmentVariable","SetHpcEnvironmentVariable") \
    rename("AddJob", "AddHpcJob")
#import <Microsoft.Hpc.Scheduler.Properties.tlb> named_guids no_namespace raw_interfaces_only */



Cluster::Cluster()
{
}

Cluster::~Cluster()
{
}
LPWSTR NodeStateStrings[] = {
	L"Offline", L"Draining", L"Ready"
};

LPWSTR JobTypeStrings[] = {
	L"Scheduled jobs", L"Command jobs", L"SOA service jobs",
	L"SOA Broker jobs"
};

LPWSTR CoreStateStrings[] = {
	L"Offline", L"Idle", L"Busy",
	L"Draining", L"Reserved"
};

/*void EnumerateNodes(IScheduler* pScheduler)
{
	HRESULT hr = S_OK;
	ISchedulerCollection* pNodes = NULL;
	ISchedulerNode* pNode = NULL;
	VARIANT var;
	long count = 0;


	// Enumerates all nodes in the cluster.
	hr = pScheduler->GetNodeList(NULL, NULL, &pNodes);
	if (FAILED(hr))
	{
		wprintf(L"pScheduler->GetJobIdList failed with 0x%x.\n", hr);
		goto cleanup;
	}

	// Get the number of items in the collection.
	hr = pNodes->get_Count(&count);
	if (FAILED(hr))
	{
		wprintf(L"pNodes->get_Count failed with 0x%x.\n", hr);
		goto cleanup;
	}

	VariantInit(&var);

	for (long i = 0; i < count; i++)
	{
		// Get an item from the collection.
		hr = pNodes->get_Item(i, &var);
		if (FAILED(hr))
		{
			wprintf(L"pNodes->get_Item failed with 0x%x.\n", hr);
			goto cleanup;
		}

		// Query the item for the ISchedulerNode interface.
		var.pdispVal->QueryInterface(IID_ISchedulerNode, reinterpret_cast<void **>(&pNode));
		VariantClear(&var);

		PrintNodeProperties(pNode);

		pNode->Release();
		pNode = NULL;
	}

cleanup:

	if (pNodes)
		pNodes->Release();;

	if (pNode)
		pNode->Release();
}



void PrintNodeProperties(ISchedulerNode *pNode)
{
	HRESULT hr = S_OK;
	ISchedulerCollection* pCollection = NULL;
	IStringCollection* pNodeGroups = NULL;
	NodeState state;
	JobType type;
	long value = 0;
	__int64 value64 = 0;
	VARIANT_BOOL flag = VARIANT_FALSE;
	BSTR bstr = NULL;
	GUID guid;
	WCHAR stringGuid[50];
	DATE date;
	SYSTEMTIME st;


	hr = pNode->get_Name(&bstr);
	if (FAILED(hr))
	{
		wprintf(L"pNode->get_Name failed with 0x%x.\n", hr);
		goto cleanup;
	}

	wprintf(L"\nProperties for node %s:\n", bstr);
	SysFreeString(bstr);

	hr = pNode->get_CpuSpeed(&value);
	if (FAILED(hr))
	{
		wprintf(L"pNode->get_CpuSpeed failed with 0x%x.\n", hr);
		goto cleanup;
	}

	wprintf(L"CpuSpeed: %.2f GHz\n", value / 1000.0);

	hr = pNode->get_Guid(&guid);
	if (FAILED(hr))
	{
		wprintf(L"pNode->get_Guid failed with 0x%x.\n", hr);
		goto cleanup;
	}

	StringFromGUID2(guid, stringGuid, sizeof(stringGuid) / sizeof(WCHAR));
	wprintf(L"Guid: %s\n", stringGuid);

	hr = pNode->get_Id(&value);
	if (FAILED(hr))
	{
		wprintf(L"pNode->get_Id failed with 0x%x.\n", hr);
		goto cleanup;
	}

	wprintf(L"Id: %ld\n", value);

	hr = pNode->get_JobType(&type);
	if (FAILED(hr))
	{
		wprintf(L"pNode>get_id failed with 0x%x.\n", hr);
		goto cleanup;
	}

	PrintSupportedJobTypes(type);

	hr = pNode->get_MemorySize(&value64);
	if (FAILED(hr))
	{
		wprintf(L"pNode->get_MemorySize failed with 0x%x.\n", hr);
		goto cleanup;
	}

	wprintf(L"Memory: %.2f GB\n", value64 / 1000.0);

	hr = pNode->get_MoveToOffline(&flag);
	if (FAILED(hr))
	{
		wprintf(L"pNode->get_MoveToOffline failed with 0x%x.\n", hr);
		goto cleanup;
	}

	wprintf(L"MoveToOffline: %s\n", (VARIANT_TRUE == flag) ? L"True" : L"False");

	hr = pNode->get_NumberOfCores(&value);
	if (FAILED(hr))
	{
		wprintf(L"pNode->get_NumberOfCores failed with 0x%x.\n", hr);
		goto cleanup;
	}

	wprintf(L"NumberOfCores: %ld\n", value);

	hr = pNode->get_NumberOfSockets(&value);
	if (FAILED(hr))
	{
		wprintf(L"pNode->get_NumberOfSockets failed with 0x%x.\n", hr);
		goto cleanup;
	}

	wprintf(L"NumberOfSockets: %ld\n", value);

	hr = pNode->get_OfflineTime(&date);
	if (FAILED(hr))
	{
		wprintf(L"pNode->get_OfflineTime failed with 0x%x.\n", hr);
		goto cleanup;
	}

	wprintf(L"OfflineTime: ");
	if (date)
	{
		if (VariantTimeToSystemTime(date, &st))
			wprintf(L"%d\\%d\\%d at %d:%d:%d.%d\n", st.wMonth, st.wDay, st.wYear, st.wHour, st.wMinute, st.wMinute, st.wMilliseconds);
		else
			wprintf(L"VariantTimeToSystemTime failed\n");
	}
	else  // date is not set
	{
		wprintf(L"\n");
	}

	hr = pNode->get_OnlineTime(&date);
	if (FAILED(hr))
	{
		wprintf(L"pNode->get_OnlineTime failed with 0x%x.\n", hr);
		goto cleanup;
	}

	wprintf(L"OnlineTime: ");
	if (date)
	{
		if (VariantTimeToSystemTime(date, &st))
			wprintf(L"%d\\%d\\%d at %d:%d:%d.%d\n", st.wMonth, st.wDay, st.wYear, st.wHour, st.wMinute, st.wMinute, st.wMilliseconds);
		else
			wprintf(L"VariantTimeToSystemTime failed\n");
	}
	else  // date is not set
	{
		wprintf(L"\n");
	}

	hr = pNode->get_Reachable(&flag);
	if (FAILED(hr))
	{
		wprintf(L"pNode->get_Reachable failed with 0x%x.\n", hr);
		goto cleanup;
	}

	wprintf(L"Reachable: %s\n", (VARIANT_TRUE == flag) ? L"True" : L"False");

	hr = pNode->get_State(&state);
	if (FAILED(hr))
	{
		wprintf(L"pNode->get_State failed with 0x%x.\n", hr);
		goto cleanup;
	}

	wprintf(L"State: %s\n", NodeStateStrings[state]);

	hr = pNode->get_NodeGroups(&pNodeGroups);
	if (FAILED(hr))
	{
		wprintf(L"pNode->get_NodeGroups failed with 0x%x.\n", hr);
		goto cleanup;
	}

	PrintNodeGroupNames(pNodeGroups);

	hr = pNode->GetCores(&pCollection);
	if (FAILED(hr))
	{
		wprintf(L"pNode->GetCores failed with 0x%x.\n", hr);
		goto cleanup;
	}

	PrintCoreInfo(pCollection);

cleanup:

	if (pCollection)
		pCollection->Release();

	if (pNodeGroups)
		pNodeGroups->Release();

	if (bstr)
		SysFreeString(bstr);
}


void PrintCoreInfo(ISchedulerCollection* pCollection)
{
	HRESULT hr = S_OK;
	ISchedulerCore* pCore = NULL;
	ITaskId* pTaskId = NULL;
	SchedulerCoreState state;
	VARIANT var;
	long coreId = 0;
	long jobId = 0;
	long taskId = 0;
	long instanceId = 0;
	long count = 0;

	hr = pCollection->get_Count(&count);
	if (FAILED(hr))
	{
		wprintf(L"pCollection->get_Count failed with 0x%x.\n", hr);
		goto cleanup;
	}

	if (count)
	{
		VariantInit(&var);

		for (long i = 0; i < count; i++)
		{
			hr = pCollection->get_Item(i, &var);
			if (FAILED(hr))
			{
				wprintf(L"pCollection->get_Count failed with 0x%x.\n", hr);
				goto cleanup;
			}

			hr = var.pdispVal->QueryInterface(IID_ISchedulerCore, (void**)&pCore);

			hr = pCore->get_Id(&coreId);
			if (FAILED(hr))
			{
				wprintf(L"pCore->get_Id failed with 0x%x.\n", hr);
				goto cleanup;
			}

			hr = pCore->get_JobId(&jobId);
			if (FAILED(hr))
			{
				wprintf(L"pCore->get_JobId failed with 0x%x.\n", hr);
				goto cleanup;
			}

			hr = pCore->get_State(&state);
			if (FAILED(hr))
			{
				wprintf(L"pCore->get_State failed with 0x%x.\n", hr);
				goto cleanup;
			}

			hr = pCore->get_TaskId(&pTaskId);
			if (FAILED(hr))
			{
				wprintf(L"pCore->get_TaskId failed with 0x%x.\n", hr);
				goto cleanup;
			}

			hr = pTaskId->get_JobTaskId(&taskId);
			if (FAILED(hr))
			{
				wprintf(L"pTaskId->get_JobTaskId failed with 0x%x.\n", hr);
				goto cleanup;
			}

			hr = pTaskId->get_InstanceId(&instanceId);
			if (FAILED(hr))
			{
				wprintf(L"pTaskId->get_InstanceId failed with 0x%x.\n", hr);
				goto cleanup;
			}

			if (SchedulerCoreState_Offline == state)
				wprintf(L"Core %ld is offline.\n", coreId);
			else if (SchedulerCoreState_Idle == state)
				wprintf(L"Core %ld is idle.\n", coreId);
			else if (SchedulerCoreState_Busy == state)
			{
				if (0 == taskId)
					wprintf(L"Core %ld is reserving resources for job %ld.\n", coreId, jobId);
				else
					wprintf(L"Core %ld is running task %ld of job %ld.\n", coreId, taskId, jobId);
			}
			else if (SchedulerCoreState_Draining == state)
				wprintf(L"Core %ld is running task %ld of job %ld "
					L"and will be taken offline when done.", coreId, taskId, jobId);

			pCore->Release();
			pCore = NULL;
			VariantClear(&var);
		}
	}
	else
		wprintf(L"There were no core objects in the collection.\n");

cleanup:

	if (pCore)
		pCore->Release();

	if (pTaskId)
		pTaskId->Release();

	VariantClear(&var);
}


void PrintSupportedJobTypes(JobType types)
{
	BOOL useDelimiter = FALSE;
	int i = 0;

	wprintf(L"Supported job types: ");

	for (i = 0; i < 32; i++)
	{
		if ((ULONG)types & (1 << i))
		{
			wprintf(L"%s%s", (useDelimiter) ? L", " : L"", JobTypeStrings[i]);
			if (!useDelimiter)
				useDelimiter = TRUE;
		}
	}

	wprintf(L"\n");
}


void PrintNodeGroupNames(IStringCollection* pNodeGroups)
{
	HRESULT hr = S_OK;
	BSTR bstrName = NULL;
	long count = 0;

	hr = pNodeGroups->get_Count(&count);
	if (FAILED(hr))
	{
		wprintf(L"pNodeGroups->get_Count failed with 0x%x.\n", hr);
	}

	if (count)
	{
		wprintf(L"Node groups to which this node belongs\n");

		for (long i = 0; i < count; i++)
		{
			hr = pNodeGroups->get_Item(i, &bstrName);
			if (FAILED(hr))
			{
				wprintf(L"pNodeGroups->get_Count failed with 0x%x.\n", hr);
				break;
			}

			wprintf(L"\t%s\n", bstrName);
			SysFreeString(bstrName);
		}
	}
}*/
