From php:7.3.3-apache-stretch
COPY src/ /var/www/html/
RUN chmod -R 777 /var/www/html/byorderoftheunionandgladiator.db
RUN apt-get update
RUN apt-get install sqlite -y
EXPOSE 80