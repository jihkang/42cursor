
mysql_install_db --user=roots
echo "CREATE DATABASE IF NOT EXISTS ${DB_DATABASE};
USE ${DB_DATABASE};
CREATE USER ${DB_USER}@'%' IDENTIFIED BY '${DB_USER_PW}';
GRANT ALL PRIVILEGES ON *.* TO ${DB_USER}@'%';
FLUSH PRIVILEGES;"> sql
mysqld -uroot --bootstrap < sql
mysqld -uroot