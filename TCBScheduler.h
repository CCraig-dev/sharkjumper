/*
 * TCBScheduler.h
 *
 *  Created on: Feb 18, 2015
 *      Author: hxr5656
 */

#ifndef TCBSCHEDULER_H_
#define TCBSCHEDULER_H_

#include <list>
#include <mqueue.h>
#include <vector>


#include "MyThread.h"
#include "TCBThread.h"



struct TaskParam
{
	int configComputeTimems;
	int configPeriodms;
	int configDeadlinems;

	// Initialize our variables to default values.
	TaskParam ()
	{
		configComputeTimems = 0;
		configPeriodms = 0;
		configDeadlinems = 0;
	}
};

class TCBScheduler: public MyThread
{
public:

	enum SchedulingStrategy
	{
		RMS,
		EDF,
		LST,
		UNDEFINED
	};

	// Its a constructor Jim. - Spock.
	TCBScheduler(std::vector <TaskParam>& threadConfigs, int iterationsPerSecond);

    virtual ~TCBScheduler() {/* empty */}

	// function that is called to run the banks main loop
	void run();

	void startSim ();

	void stopSim ();

	void stop();

	void setSimTime(int newSimTimeSec);

	int getSimTime() {return simTimeSec; }

	void setSchedulingStrategy(SchedulingStrategy newStrategy);

	SchedulingStrategy getSchedulingStrategy() {return strategy; }


private:
    // Implementation of our code from mythreadclass.h
	virtual void InternalThreadEntry();

    void initializeSim();

    void updatetimeSpec (timespec & time, int valuems);

	void rateMonotinicScheduler(TCBThread* runingTCBThread);

	void rateMonotinicSchedulerIncompleteTask(TCBThread* runingTCBThread);

//  void leastSlackTime();
//  void EarliestDeadlineFirst();

	mqd_t toSchedmq;

	bool running;
	bool simRunning;

	int simTimeSec;

	SchedulingStrategy strategy;

	timespec startSimTime;
	timespec endSimTime;

	std::vector <TCBThread> TCBThreads;

	std::list <TCBThread*> TCBThreadQueue;
	std::list <TCBThread*> startTCBThreadQueue;

	// Pointer this classe's message queue.
};

#endif /* TCBSCHEDULER_H_ */
