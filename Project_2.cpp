// CS 1337.010 Project 2 <bxm170330> <Bishesh Manandhar>

#include <iostream>
#include <iomanip>

using namespace std;

// Enumerator for vital and activity used to track info type
enum Patient {VITAL, ACTIVITY};

// Creating structure for patient vital information
struct VitalInfo
{
	float temperature;
	unsigned int systolicPressure;
	unsigned int diastolicPressure;
};

// Creating structure for patient activity information
struct ActivityInfo
{
	unsigned int stepCount;
	unsigned int sleepHours;
};

// Union that nests VitalInfo and ActivityInfo
union Process
{
	VitalInfo vitalMember;
	ActivityInfo activityMember;
};

// Final structure that nests union and enumerator
struct Final
{
	Process patientInfo;
	Patient patientInfoType;
};


int main()
{
	// integer to hold user choice (1, 2, 3)
	int userAction;

	// Creating array of final structures
	Final array[100];

	// Setting stop processing to false
	bool stopProcessing = false;

	// Counters for vital and activity info
	int countVital = 0;
	int countActivity = 0;
	int countVitalOrActivity = 0;

	// variables to check values for vital and activity info
	int systolicPressureCheck;
	int diastolicPressureCheck;
	float tempCheck;
	int stepCountCheck;
	int sleepHourCheck;

	// Counter for index values of array
	int index = 0;

	// do while loop to process data
	do
	{
		// User prompt that takes in user choice
		cout << "Please enter the number for the desired action (1, 2, 3):" << endl;
		cout << "  1 - Enter some patient vital information" << endl;
		cout << "  2 - Enter some patient activity information" << endl;
		cout << "  3 - Print summary information on the patient information and exit the program" << endl;
		cin >> userAction;

		// If userAction not valid, display error message
		if ((userAction != 1 && userAction != 2 && userAction != 3) || cin.fail())
		{
			cin.clear();
			cin.ignore(5, '\n');
			cout << "Please enter 1, 2, or 3" << endl;
		}
		// If user chooses vital info, process vital information
		else if (userAction == 1)
		{
			array[index].patientInfoType = VITAL;

			// Checking and getting the temperature. Storing value in array
			cout << "Enter the temperature: ";
			cin >> tempCheck;
			while(cin.fail())
			{
				cin.clear();
				cin.ignore(5, '\n');
				cout << "Please enter a float: ";
				cin >> tempCheck;
			}
			array[index].patientInfo.vitalMember.temperature = tempCheck;

			// Getting value for systolic pressure, then storing it in array
			cout << "Enter the systolic pressure: ";
			cin >> systolicPressureCheck;
			while (systolicPressureCheck < 0 || cin.fail())
			{
				cin.clear();
				cin.ignore(5, '\n');
				cout << "Please enter an integral unsigned number" << endl;
				cout << "Enter the systolic pressure: ";
				cin >> systolicPressureCheck;
			}
			array[index].patientInfo.vitalMember.systolicPressure = systolicPressureCheck;

			// Getting value for diastolic pressure, then storing it in array
			cout << "Enter the diastolic pressure: ";
			cin >> diastolicPressureCheck;
			while (diastolicPressureCheck < 0 || cin.fail())
			{
				cin.clear();
				cin.ignore(5, '\n');
				cout << "Please enter an integral unsigned number" << endl;
				cout << "Enter the diastolic pressure: ";
				cin >> diastolicPressureCheck;
			}
			array[index].patientInfo.vitalMember.diastolicPressure = diastolicPressureCheck;

			// Incrementing index values and counters by one
			index++;
			countVital++;

		}
		// If user chooses activity info, process patient activity info
		else if (userAction == 2)
		{
			array[index].patientInfoType = ACTIVITY;

			// Getting value for step count and storing it in array
			cout << "Enter the step count: ";
			cin >> stepCountCheck;
			while (stepCountCheck < 0 || cin.fail())
			{
				cin.clear();
				cin.ignore(5, '\n');
				cout << "Please enter an integral unsigned number" << endl;
				cout << "Enter the step count: ";
				cin >> stepCountCheck;
			}
			array[index].patientInfo.activityMember.stepCount = stepCountCheck;

			// Getting value for sleep hours and storing it in array
			cout << "Enter the sleep hours: ";
			cin >> sleepHourCheck;
			while(sleepHourCheck < 0 || cin.fail())
			{
				cin.clear();
				cin.ignore(5, '\n');
				cout << "Please enter an integral unsigned number" << endl;
				cout << "Enter the sleep hours: ";
				cin >> sleepHourCheck;
			}
			array[index].patientInfo.activityMember.sleepHours = sleepHourCheck;

			// Incrementing index and counter variables by one
			index++;
			countActivity++;
		}
		// If user wants to print info, print report
		else if(userAction == 3)
		{
			// If user wishes to print info while no info has been recorded, display message
			if(countVitalOrActivity == 0)
			{
				cout << "No information for the patient has been recorded." << endl;
				cout << endl;
				stopProcessing = true;
			}
			// Else proceed to analyze report
			else
			{
				// Creating variables for vital info analysis
				int numVitalRecords = countVital;
				float maxTempVital = 0;
				float minTempVital = 0;
				unsigned int maxSystolicVital = 0;
				unsigned int minSystolicVital = 0;
				unsigned int maxDiastolicVital = 0;
				unsigned int minDiastolicVital = 0;

				// Creating variables for activity info analysis
				int numActivityRecords = countActivity;
				unsigned int stepCountSum = 0;
				unsigned int sleepHourSum = 0;

				// Creating initial values for vital info in order to find max and min
				// when passing through array
				int maxTempPass = 1,
						minTempPass = 1,
						maxSystolicPass = 1,
						minSystolicPass = 1,
						maxDiastolicPass = 1,
						minDiastolicPass = 1;

				// Loop to pass through array and perform analysis
				for (int i = 0; i < index; ++i)
				{
					// Analysis for vital information
					if(array[i].patientInfoType == VITAL)
					{
						if(maxTempPass == 1)
						{
							maxTempVital = array[i].patientInfo.vitalMember.temperature;
							maxTempPass++;
						}

						if(array[i].patientInfo.vitalMember.temperature > maxTempVital)
						{
							maxTempVital = array[i].patientInfo.vitalMember.temperature;
						}

						if(minTempPass == 1)
						{
							minTempVital = array[i].patientInfo.vitalMember.temperature;
							minTempPass++;
						}

						if(array[i].patientInfo.vitalMember.temperature < minTempVital)
						{
							minTempVital = array[i].patientInfo.vitalMember.temperature;
						}

						if(maxSystolicPass == 1)
						{
							maxSystolicVital = array[i].patientInfo.vitalMember.systolicPressure;
							maxSystolicPass++;
						}

						if(array[i].patientInfo.vitalMember.systolicPressure > maxSystolicVital)
						{
							maxSystolicVital = array[i].patientInfo.vitalMember.systolicPressure;
						}

						if(minSystolicPass == 1)
						{
							minSystolicVital = array[i].patientInfo.vitalMember.systolicPressure;
							minSystolicPass++;
						}

						if(array[i].patientInfo.vitalMember.systolicPressure < minSystolicVital)
						{
							minSystolicVital = array[i].patientInfo.vitalMember.systolicPressure;
						}

						if(maxDiastolicPass == 1)
						{
							maxDiastolicVital = array[i].patientInfo.vitalMember.diastolicPressure;
							maxDiastolicPass++;
						}

						if(array[i].patientInfo.vitalMember.diastolicPressure > maxDiastolicVital)
						{
							maxDiastolicVital = array[i].patientInfo.vitalMember.diastolicPressure;
						}

						if(minDiastolicPass == 1)
						{
							minDiastolicVital = array[i].patientInfo.vitalMember.diastolicPressure;
							minDiastolicPass++;
						}

						if(array[i].patientInfo.vitalMember.diastolicPressure < minDiastolicVital)
						{
							minDiastolicVital = array[i].patientInfo.vitalMember.diastolicPressure;
						}
					}

					// Analysis for activity information
					if (array[i].patientInfoType == ACTIVITY)
					{
						stepCountSum += array[i].patientInfo.activityMember.stepCount;
						sleepHourSum += array[i].patientInfo.activityMember.sleepHours;
					}
				}

				// Used to show one point after decimal when printed out
				cout << fixed << setprecision(1);

				// Printing out vital analysis of patient
				cout << "Number of patient vital information records: " << setw(3) << numVitalRecords << endl;
				cout << "  Maximum temperature: " << setw(29) << maxTempVital << endl;
				cout << "  Minimum temperature: " << setw(28) << minTempVital << endl;
				cout << "  Maximum systolic pressure: " << setw(21) << maxSystolicVital << endl;
				cout << "  Minimum systolic pressure: " << setw(21) << minSystolicVital << endl;
				cout << "  Maximum diastolic pressure: " << setw(20) << maxDiastolicVital << endl;
				cout << "  Minimum diastolic pressure: " << setw(20) << minDiastolicVital << endl;
				cout << endl;

				// Printing out activity analysis of patient
				cout << "Number of patient activity information records: " << setw(2) << numActivityRecords << endl;
				cout << "  Total step count: " << setw(34) << stepCountSum << endl;
				cout << "  Total sleep hours: " << setw(30) << sleepHourSum << endl;

				// Set stopProcessing to true to exit do while loop
				stopProcessing = true;
			}
		}

		// Increment how many times user has been displayed prompt
		countVitalOrActivity++;
		cout << endl;

	} while (stopProcessing == false);	// End of do while loop

	return 0;
}	// End of function main()
