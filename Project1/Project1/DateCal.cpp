#include "DateCal.h"

string dateCal(string currentTime, string dueTime)
{
	time_t		cuTime;
	time_t		dTime;
	int			remainHour, remainMin, temp;
	double		d_Remain;

	string remainingTime(""); // 2017:10:23:23:59

	struct tm curTime;
	curTime.tm_year = stoi(currentTime.substr(0, 4))	 - 1900;	// ����: �⵵�� 1900���� ����
	curTime.tm_mon = stoi(currentTime.substr(5, 7))		 - 1;		// ����: ���� 0���� ����
	curTime.tm_mday = stoi(currentTime.substr(8, 10));
	curTime.tm_hour = stoi(currentTime.substr(11, 13));
	curTime.tm_min = stoi(currentTime.substr(14, 16));
	curTime.tm_sec = 0;				// �� ���� ��� ����
	curTime.tm_isdst = 0;			// ���Ÿ�� ��� ����

	struct tm duTime;
	duTime.tm_year = stoi(dueTime.substr(0, 4)) - 1900;	
	duTime.tm_mon = stoi(dueTime.substr(5, 7)) - 1;		
	duTime.tm_mday = stoi(dueTime.substr(8, 10));
	duTime.tm_hour = stoi(dueTime.substr(11, 13));
	duTime.tm_min = stoi(dueTime.substr(14, 16));
	duTime.tm_sec = 0;				// �� ���� ��� ����
	duTime.tm_isdst = 0;			// ���Ÿ�� ��� ����

	cuTime = mktime(&curTime);
	dTime = mktime(&duTime);

	d_Remain = difftime(dTime, cuTime);

	temp = (int)d_Remain;
	if (temp < 0) {
		remainingTime = "now Running Vote";
		return remainingTime;
	}

	remainHour = temp / (60 * 60);
	temp = temp - (remainHour * 60 * 60);

	remainMin = temp / 60;

	if (remainHour != 0) {
		remainingTime = std::to_string(remainHour) + " hour ";

		if (remainMin != 0) {
			remainingTime = remainingTime + std::to_string(remainMin) + " min";
		}

		remainingTime = remainingTime + " left";
	}
	else
	{
		if (remainMin != 0) remainingTime = std::to_string(remainMin) + " min left";

		else remainingTime = "now Running Vote";
	}

	return remainingTime;
}
