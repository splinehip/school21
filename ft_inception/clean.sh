sudo docker rm -f $(docker ps -qa);
sudo docker rmi -f $(docker images -qa);
