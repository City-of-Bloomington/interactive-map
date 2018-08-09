#!/bin/bash
# Creates a tarball containing a full snapshot of the data in the site
#
# @copyright Copyright 2015-2018 City of Bloomington, Indiana
# @license https://www.gnu.org/licenses/agpl-3.0.txt GNU/AGPL, see LICENSE
APPLICATION_NAME="maps"
APPLICATION_HOME="/srv/sites/$APPLICATION_NAME"
BACKUP_DIR="/srv/backup/$APPLICATION_NAME"
SITE_HOME="$APPLICATION_HOME/data"
CRON_LOG="/var/log/cron/${APPLICATION_NAME}"
MYSQL_CREDENTIALS="/etc/cron.daily/backup.d/${APPLICATION_NAME}.cnf"
MYSQL_DBNAME="$APPLICATION_NAME"

#----------------------------------------------------------
# Backups
#----------------------------------------------------------
# How many days worth of tarballs to keep around
num_days_to_keep=5

now=`date +%s`
today=`date +%F`

# Dump the database
mysqldump --defaults-extra-file=$MYSQL_CREDENTIALS $MYSQL_DBNAME > $SITE_HOME/$MYSQL_DBNAME.sql
cd $SITE_HOME
tar czf $today.tar.gz $MYSQL_DBNAME.sql maps
mv $today.tar.gz $BACKUP_DIR

# Purge any backup tarballs that are too old
cd $BACKUP_DIR
for file in `ls`
do
	atime=`stat -c %Y $file`
	if [ $(( $now - $atime >= $num_days_to_keep*24*60*60 )) = 1 ]
	then
		rm $file
	fi
done

touch $CRON_LOG
