cp /influxdb.conf /etc/influxdb/influxdb.conf


/etc/init.d/influxdb start
curl -XPOST "http://localhost:8086/query" --data-urlencode "q=CREATE USER admin WITH PASSWORD 'root' WITH ALL PRIVILEGES"
curl --user admin:root -XPOST "http://localhost:8086/query" --data-urlencode "q=CREATE USER telegraf WITH PASSWORD 'root'"
curl --user admin:root -XPOST "http://localhost:8086/query" --data-urlencode "q=CREATE DATABASE 'telegraf'"
curl --user admin:root -XPOST "http://localhost:8086/query" --data-urlencode "q=GRANT ALL ON telegraf TO telegraf"
curl --user admin:root -XPOST "http://localhost:8086/query" --data-urlencode "q=CREATE USER grafana WITH PASSWORD 'root'"
curl --user admin:root -XPOST "http://localhost:8086/query" --data-urlencode "q=GRANT READ ON telegraf TO grafana"
telegraf config > telegraf.conf

cp /telegraf.conf /etc/telegraf/telegraf.conf

/etc/init.d/telegraf start 

apt-get install apt-transport-https software-properties-common wget -y

wget -qO- https://packages.grafana.com/gpg.key |  apt-key add

apt-get update -y

echo "deb https://packages.grafana.com/oss/deb stable main" |  tee -a /etc/apt/sources.list.d/grafana.list

apt-get update -y

apt-get install grafana -y

#cp /sample.yaml /ect/grafana/provisioning/datasources/

#/etc/init.d/grafana-server start
#/etc/init.d/telegraf start

#telegraf
