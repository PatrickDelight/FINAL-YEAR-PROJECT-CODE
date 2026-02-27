# DIGITAL TWIN ANN -FINAL-YEAR-PROJECT-CODE
All the codes contained in this repo, are those used for the implementation of a digital twin model of a solar panel

The JointSketch was used to obtain data from the solar panel via arduino and the sensors used, the sensors used were the dht11 temperature and humidty sensor, acs 712 current sensor, a voltage sensor, then the light dependent sensor

The python program used an http get request to send data to the google cloud platform after reading data from the microcontroller via serial communication

Then the javascript file does the scripting on the cloud and places the data obtained from the get request into the appropriate location in the sheet

This data is imported into Matlab and used to train a bayesian regularization ANN (Test.m), which was represented in the simulink as a Matlab Function.
This function was used to predict power from the panel in real time. another logic function does the comparison and classification of faults 
