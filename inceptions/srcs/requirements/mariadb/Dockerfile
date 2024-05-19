FROM debian:11

EXPOSE 3306

RUN  apt-get update && \
    apt-get upgrade && \
    apt-get -y install mariadb-server mariadb-client && \
    mkdir -p /var/run/mysqld && \
    chown mysql:mysql /var/run/mysqld

COPY ./tools/config.sh /tmp/
COPY ./conf/my.cnf /etc/mysql

RUN chmod +x /tmp/config.sh

ENTRYPOINT sh /tmp/config.sh