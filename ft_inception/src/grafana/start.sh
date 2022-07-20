cp /sample.yaml /etc/grafana/provisioning/datasources/
/etc/init.d/grafana-server restart
/etc/init.d/grafana-server start
/etc/init.d/telegraf start

/etc/init.d/influxdb restart 

telegraf
