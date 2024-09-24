# FINAL-YEAR-PROJECT-CODE
All the codes contained in this repo, are those used for the implementation of a digital twin model of a solar panel

The JointSketch was used to obtain data from the solar panel via arduino and the sensors used, the sensors used were the dht11 temperature and humidty sensor, acs 712 current sensor, a voltage sensor, then the light dependent sensor

The python program used an http get request to send data to the google cloud platform after reading data from the microcontroller via serial communication

Then the javascript file does the scripting on the cloud and places the data obtained from the get request into the appropriate location in the sheet
