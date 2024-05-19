FROM debian:11

EXPOSE 9000

RUN apt-get update && apt-get upgrade && apt-get install -y wordpress \
    php7.4-fpm curl wget php7.4-mysql
RUN mkdir -p /var/www
RUN wget https://wordpress.org/latest.tar.gz
RUN tar -xvf latest.tar.gz && mv /wordpress/* /var/www
RUN chown -R www-data:www-data /var/www
RUN rm -r /wordpress latest.tar.gz


COPY ./conf/www.conf /etc/php/7.4/fpm/pool.d
COPY ./conf/wp-config.php /var/www
COPY ./tools/config.sh /tmp
RUN chmod +x /tmp/config.sh

ENTRYPOINT ["sh", "/tmp/config.sh"]