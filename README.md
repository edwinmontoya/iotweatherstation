# project: IoT Weather Station #
## EAFIT University, Systems Engineering, 20171 ##

### authors: Edwin Montoya Munera - emontoya@eafit.edu.co and David Velasquez - dvelas25@eafit.edu.co ###

github: https://github.com/edwinmontoya/iotweatherstation.git

## 1. arduino/iotws-testWebGetTime/* ##

* Description: 

This program test the connection to the server "iotweatherstation" in order to obtain the Date (day+hour) in format: yyyy:mm:dd:hh:mm:ss
The connection is done throught Wifi network and HTTP Connection. It uses GET Method.

# Servidor IoTServer

Se implementan los servicios:

* getTime: Obtiene el dia+hora en formato: yyyy:mm:dd:hh:mm:ss

    http://iotserver1.dis.eafit.edu.co/weather/getTime
    
* saveSensors: guarda en Base de Datos los valores de Temperatura + Humedad.

    http://iotserver1.dis.eafit.edu.co/weather/saveSensors?idHome=<home>&temp=<val_temp>&humid=<val_humid>&timestamp=<day+hour>
    
    
    
  


