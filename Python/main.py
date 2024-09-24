import serial
import requests

# Replace with your Google Apps Script Web App URL
GAS_URL = 'https://script.google.com/macros/s/AKfycbyBxNVYAD6hxkLZO46yCfModUEb-TruwtSdRl4m1C-MwDeQWs0Wt6eGkQMhQX1HKaYI/exec'

# Set up the serial connection (replace 'COM3' with your port and set the baud rate)
ser = serial.Serial('COM3', 9600)

def send_data_to_google_sheet(temperature, humidity, solar_radiation,power): #removed SR and P
    # Prepare the query parameters
    params = {
        'T': temperature, #changed temperature to T
        'H': humidity, #changed Humidity to H
        'SR': solar_radiation,
        'P': power
    }

    # Send the HTTP GET request
    response = requests.get(GAS_URL, params=params)
    
    # Print the response from the server (for debugging)
    print(response.text)

def main():
    while True:
        # Read a line from the serial connection
        line = ser.readline().decode('utf-8').strip()

        # Assuming the Arduino sends data in CSV format like "25.3,60,800,100"
        data = line.split(',')

        if len(data) == 4: #changed 4 to 2
            temperature = data[0] 
            humidity = data[1]
            solar_radiation = data[2]
            power = data[3]

            # Send the data to the Google Sheet
            send_data_to_google_sheet(temperature, humidity, solar_radiation, power) #removed SR and P

if __name__ == '__main__':
    main()

