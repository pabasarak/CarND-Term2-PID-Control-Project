
# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

# PID Control Project - Reflections

## P – Proportional 
The Proportional coefficient (Kp) determines the correction correlation of the turning angle for a given error. For a given error, the high Kp will result with a large turning angle and low Kp will result with a small turning angle. Due to this Kp will govern how quickly the error gets rectify.
When it comes to the Project, having a large Kp will makes to vehicle to quickly correct the error. However, it will result with overshooting and then oscillation. The suitable Kp for the project environment was found as 5.

## I – Integral
The Integral coefficient (Ki) determines the correction correlation to the accumulated error. This Ki is used to correct the bias error of the system.
When it comes to the project, Ki will fix the drift in the steering. The suitable Ki for the project environment was found as 1.0.

## D- Derivative
The Derivative coefficient (Kd) determines the correction correlation to the rate of change of error. This Ki will dampen system when there is an oscillation or overshoot.
When it come to the project, the suitable Kp for was found as 30.

## PID Hyper parameter tuning
Tuning the hyper parameters is very interesting task as there is no single answer for that. 
First, I stared with manual tuning by adding random numbers. It resulted with high oscillation and driving the vehicle out of track within driving a small distance.
Then I implemented the twiddle algorithm and made it automatically tune the parameters. The main goal was to drive the car whole track (at any speed). The maximum speed was set to 20mph, max throttle 0.3 and if there is an error or over speed, the throttle is 0.1.

From that I found that  PID coefficients as Kp,Ki,Kd { 26.86, 0.000076, -0.233}. Though it goes around the track, the maximum speed around 10mph. 
The next step was to increase the speed. So I used max throttle to 0.6 with same PID parameters. This increased the average speed to about 20mph. However, it introduced large oscillations that throw the car out of the track.
The parameters we re-tuned again with twiddling and found PID coefficients as Kp,Ki,Kd { 10.53, 0.0076, -19.65}. However, this also has some significant oscillations. 
Then the parameters were manually tuned and found Kp,Ki,Kd { 5, 1, 30} will result with smooth steering around the track while achieving maximum speed about 35mph.

Final output video id found here
https://youtu.be/bpr_ajhqNTE

## Note: 
The initial coefficient plays a significant role when tuning the coefficients using Twiddling.



---

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

## Editor Settings

We've purposefully kept editor configuration files out of this repo in order to
keep it as simple and environment agnostic as possible. However, we recommend
using the following settings:

* indent using spaces
* set tab width to 2 spaces (keeps the matrices in source code aligned)

## Code Style

Please (do your best to) stick to [Google's C++ style guide](https://google.github.io/styleguide/cppguide.html).

## Project Instructions and Rubric

Note: regardless of the changes you make, your project must be buildable using
cmake and make!

More information is only accessible by people who are already enrolled in Term 2
of CarND. If you are enrolled, see [the project page](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/f1820894-8322-4bb3-81aa-b26b3c6dcbaf/lessons/e8235395-22dd-4b87-88e0-d108c5e5bbf4/concepts/6a4d8d42-6a04-4aa6-b284-1697c0fd6562)
for instructions and the project rubric.

## Hints!

* You don't have to follow this directory structure, but if you do, your work
  will span all of the .cpp files here. Keep an eye out for TODOs.

## Call for IDE Profiles Pull Requests

Help your fellow students!

We decided to create Makefiles with cmake to keep this project as platform
agnostic as possible. Similarly, we omitted IDE profiles in order to we ensure
that students don't feel pressured to use one IDE or another.

However! I'd love to help people get up and running with their IDEs of choice.
If you've created a profile for an IDE that you think other students would
appreciate, we'd love to have you add the requisite profile files and
instructions to ide_profiles/. For example if you wanted to add a VS Code
profile, you'd add:

* /ide_profiles/vscode/.vscode
* /ide_profiles/vscode/README.md

The README should explain what the profile does, how to take advantage of it,
and how to install it.

Frankly, I've never been involved in a project with multiple IDE profiles
before. I believe the best way to handle this would be to keep them out of the
repo root to avoid clutter. My expectation is that most profiles will include
instructions to copy files to a new location to get picked up by the IDE, but
that's just a guess.

One last note here: regardless of the IDE used, every submitted project must
still be compilable with cmake and make./
