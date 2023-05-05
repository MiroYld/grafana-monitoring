# `grafana monitoring using qt tcp client`

## Prerequisites
```
1) Docker engine version >= 18.02.0+ 
2) Docker-compose version >= 2.15.1
```

## Functioning

### Fichier config.json
the telegraf collection agent is configured as a tcp server. 
It collects metrics using the tcp client which is coded in c++ qt. 
Prometheus allows data collected by telegraf to be exposed to the grafana service

### usage
```bash
$ https://github.com/MiroYld/grafana-monitoring.git
$ cd grafana-monitoring
$ docker-compose up --build
```
### urls
You can check the proper functioning of the stack via the following urls:
```
prometheus: http://localhost:9090/graph
grafana : http://localhost:3000/ 

login grafana: admin
password grafana: admin
```
The url to use for the datasource in grafana
```
datasource: http://prometheus:9090
```

you can enter 
```
socket_listener{card="1"} or socket_listener{card="2"}
``` 
in the prometheus query to display the result

There is only one label available at the moment which is 
```
humidity
```