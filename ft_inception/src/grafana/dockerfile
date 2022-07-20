FROM debian:buster
RUN apt upgrade -y
RUN apt update -y
RUN apt-get install gpg wget -y

RUN wget -qO- https://repos.influxdata.com/influxdb.key |  apt-key add -

RUN echo "deb https://repos.influxdata.com/debian buster stable" |  tee -a /etc/apt/sources.list.d/influxdb.list

RUN apt-get update -y

RUN apt-get install influxdb telegraf -y

COPY ./influxdb.conf .

EXPOSE 3000 8086

COPY ./telegraf.conf .
COPY ./setup.sh .
COPY ./start.sh .
COPY ./sample.yaml .
RUN bash setup.sh
CMD ["bash", "start.sh"]
