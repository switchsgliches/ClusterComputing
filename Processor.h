#pragma once
#include <string>

class Processor
{
private:
	std::string name;
	std::string model;
	std::string socket;
	int OpsPerCycle;
	double clockSpeed;
	double hostSpeed;
	double size;
	int logicalCores;
	int physicalCores;
	double power;
	int OpEff;
	int FLOPS;

public:
	Processor();
	Processor(std::string n, std::string m, std::string soc,int OpsPerCycle,double clock,
		double host, double sz, int log, int phys, double pow, int flops, int OPEFF);
	
	void setName(std::string n) { name = n; };
	void setModel(std::string mod) { model = mod; };
	void setSocket(std::string soc) { socket = soc; };
	void setOPSPERCYC(int OPSPERCYC) { OpsPerCycle = OPSPERCYC; }
	void setClockSpeed(double clock) { clockSpeed = clock; };
	void setHostSpeed(double host) { hostSpeed = host; };
	void setCacheSize(double cs) { size = cs; };
	void setLogicalCores(int lc) { logicalCores = lc; };
	void setPhysicalCores(int pc) { physicalCores = pc; };
	void setPowerConsumption(double pow) { power = pow; };
	void setOpEff(int OPEFF) { OpEff - OPEFF;  }
	void setFLOPS(int flops) { FLOPS = (((clockSpeed*physicalCores)*OpsPerCycle));}

	std::string getName() { return name; };
	std::string getModel() { return model; };
	std::string getSocket() { return socket; };
	int getOPSPERCYC() { return OpsPerCycle; }
	double getClockSpeed() { return clockSpeed; };
	double getHostSpeed() { return hostSpeed; };
	double getCacheSize() { return size; };
	int getLogicalCores() { return logicalCores; };
	int getPhysicalCores() { return physicalCores; }
	double getPowerConsumption() { return power; };
	int getOPEFF() { return OpEff;  }
	int getGFLOPS() { return FLOPS; }

	std::string getData()
	{
		std::string outString = "";

		outString = "Name: " + this->getName() 
			+ "\r\nModel: " + this->getModel() 
			+"\r\nSocket: " + this->getSocket()
			+ "\r\nOperations Per Cycle: " + std::to_string(this->getOPSPERCYC())
			+ "\r\nClock Speed: " + std::to_string(this->getClockSpeed()) 
			+ "\r\nHost Speed: " + std::to_string(this->getHostSpeed()) 
			+ "\r\nCache Size: " + std::to_string(this-> getCacheSize()) 
			+ "\r\nLogical Cores: " + std::to_string(this->getLogicalCores()) 
			+ "\r\nPhysical Cores: " + std::to_string(this->getPhysicalCores()) 
			+ "\r\nPower Consumption: " + std::to_string(this->getPowerConsumption()) 
			+ "\r\nOperating Eff.: %" + std::to_string(this->getOPEFF())
			+ "\r\nGFLOPS: " + std::to_string(this->getGFLOPS())
			+"\r\n";

		return outString;
	}

};