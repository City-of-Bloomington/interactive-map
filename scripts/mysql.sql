-- @copyright 2006-2012 City of Bloomington, Indiana
-- @license http://www.gnu.org/copyleft/gpl.html GNU/GPL, see LICENSE.txt
-- @author Cliff Ingham <inghamn@bloomington.in.gov>
create table people (
	id int unsigned not null primary key auto_increment,
	firstname varchar(128) not null,
	lastname  varchar(128) not null,
	email     varchar(255) not null,
	username  varchar(40) unique,
	password  varchar(40),
	role      varchar(30),
	authenticationMethod varchar(40)
);

create table maps (
    id    int unsigned not null primary key auto_increment,
    name  varchar(128) not null unique,
    alias varchar(128) not null unique,
    internalFilename varchar(32) not null,
    navigationMarkdown text,
    relatedMarkdown    text,
    media_id int unsigned
);
