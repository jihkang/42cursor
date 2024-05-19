FROM debian:11

EXPOSE 443

RUN apt-get update && apt-get install -y nginx openssl

COPY ./conf/default /etc/nginx/sites-available
RUN chmod +x /etc/nginx/sites-available/default

RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -keyout /etc/ssl/jihkang.key -out /etc/ssl/jihkang.crt \
    -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=jihkang"

RUN     chmod 700 /etc/ssl/jihkang.crt
RUN     chmod 700 /etc/ssl/jihkang.key

ENTRYPOINT ["nginx", "-g", "daemon off;"]