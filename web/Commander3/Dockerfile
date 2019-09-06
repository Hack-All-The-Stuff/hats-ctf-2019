From php:7.3.3-apache-stretch
COPY src/ /var/www/html/
RUN mkdir /flag
COPY flag/ /flag
RUN chmod -R 775 /flag
RUN chown -R root:root /var/www/
RUN chown -R root:root /flag
EXPOSE 80