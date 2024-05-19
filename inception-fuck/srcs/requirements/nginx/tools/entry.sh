openssl req -x509 -nodes -days 365 -newkey \
        rsa:2048 -keyout /etc/ssl/siwolee.key \
        -out /etc/ssl/siwolee.crt \
        -subj "/C=KR/ST=Seoul/L=Gaepo-dong/O=42seoul/CN=*.$DOMAIN/"
