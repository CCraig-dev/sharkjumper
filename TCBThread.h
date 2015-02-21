#ifndef _TCBTHREAD_H_
#define _TCBTHREAD_H_

#include <Time.h>
#include "MyThread.h"

class TCBThread: public MyThread
{
public:
	// Its a constructor Jim. - Spock.
	TCBThread(int configComputeTimems, int configPeriodms, int configDeadlinems,
			  long iterationsPerSecond, int configThreadNumber);

    virtual ~TCBThread() {/* empty */}

    int getComputeTime() { return computeTimems; }
    int getdeadline() { return deadlinems; }
    int getperiodms() { return periodms; }

    timespec getNextPeriod () {return nextPeriod; }

    timespec getNextDeadline () {return nextDeadline; }

    void SetNextPeriod (timespec & newPeriod) {nextPeriod = newPeriod;}
    void SetNextDeadline (timespec & newDeadline) {nextPeriod = newDeadline;}

	// function that is called to run the banks main loop
	void run();

	void startNewComputePeriod ();

	void suspend ();

	void resume ();

	void stop();

	// debug functions this will die in the release version.
	long getdoWork() { return doWork; }

private:
    // Implementation of our code from mythreadclass.h
	virtual void InternalThreadEntry();

	int computeTimems;
	int deadlinems;
	int periodms;

	int TCBThreadNumber;

	int computeTimeExecutedms;
	int periodExecutedms;
	long doWork;

	timespec nextPeriod;
	timespec nextDeadline;

	long computeTimeIterations;

	bool running;

	// Protects the customerQueue;
	pthread_mutex_t TCBMutex;
};
#endif
