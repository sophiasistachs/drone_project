#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

// Decription: 
// This code simnulates a race car's speed monitoring system by tracking position changes
// over time. Each iteration generates random x,y cordinates representing sensor readings, 
// stoes both the previous and current positions in a vector, then calculates speed by dividing
// the straight-line distance between positions by the elapsed time. After displaying the speed, 
// it removes the old position from the vector to maintain only the two most recent coordinates, 
// then waits before the next sensor reading. 

// Some Essential Assumptions:
// This code calculates only magnitude since we are tracking speed and not velocity therefore no negative values are outputed. 
// Asume the vector inputs are obtained from some sensor readings AE gyroscope, gps, etc.
// Asume sensor unit is in meters


// Function Declaration
double calculate_speed(const vector<double>& car_pos, int time);

int main() {


	vector <double> car_pos = { 0, 0 };	// Initial position 
	int sensor_time = 2000; // Time in miliseconds -> can be modified to any nonzero positive number 

	srand(time(nullptr));

	while (true) {

		// Generate random number to simulate continous sensor output
		double sensor_out_x = (rand() % 100) + 1;
		double sensor_out_y = (rand() % 100) + 1;
		// Update vector based on sensor output 
		car_pos.push_back(sensor_out_x);
		car_pos.push_back(sensor_out_y);

		// Call function to calculate speed
		double speed = calculate_speed(car_pos, sensor_time);
		cout << "Speed: " << speed << " m/sec" << endl;

		// Remove first 2 elements of Vector for memory management
		car_pos.erase(car_pos.begin());
		car_pos.erase(car_pos.begin());

		Sleep(sensor_time); // Wait for next sensor reading
	}

	return 0;
}

// Function to calculate avg speed
double calculate_speed(const vector <double>& car_pos, int sensor_time) {

	double distance_traveled = sqrt(pow(car_pos[2] - car_pos[0], 2) + pow(car_pos[3] - car_pos[1], 2));	// Pythagorean theorem to calculate distance from the given cordinates

	double avg_speed = distance_traveled / (sensor_time / 1000);	// Calculate speed and convert miliseconds to secods

	return avg_speed;
}