# debian latest(12), buster(10) 
FROM debian:buster

EXPOSE	443

COPY        ./conf/default /etc/nginx/conf.d

RUN         apt-get update -y && apt-get upgrade -y && \
    apt-get install -y nginx openssl
RUN         openssl req -x509 -nodes -days 365 -newkey \
    rsa:2048 -keyout /etc/ssl/siwolee.key \
    -out /etc/ssl/siwolee.crt \
    -subj "/C=KR/ST=Seoul/L=Gaepo-dong/O=42seoul/CN=*.siwolee.42.fr/"

COPY 	    ./conf/default /etc/nginx/site-available
# COPY        ./conf/myconf.conf /etc/nginx/conf.d
# COPY        ./tools/entry.sh /tmp
RUN	    chmod 700 /etc/ssl/siwolee.key
RUN	    chmod 700 /etc/ssl/siwolee.crt

RUN         apt-get install -y netcat curl;

ENTRYPOINT   ["nginx", "-g", "daemon off;"]

