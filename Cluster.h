#pragma once
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

class Cluster
{
public:
	Cluster();
	~Cluster();

	/*void EnumerateNodes(IScheduler* pScheduler);
	void PrintNodeProperties(ISchedulerNode *pNode);
	void PrintCoreInfo(ISchedulerCollection* pCollection);
	void PrintSupportedJobTypes(JobType types);
	void PrintNodeGroupNames(IStringCollection* pNodeGroups);*/

private:

};

