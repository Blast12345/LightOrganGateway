# Synesthetic Gateway

This project facilitates communication between the server and the clients. 

The clients communicate via the ESP-NOW protocol. Only ESP devices can communicate over that protocol, so the server needs to go through a middle-man (the gateway). The gateway receives data from the server and will route the data accordingly over the ESP-NOW network.
