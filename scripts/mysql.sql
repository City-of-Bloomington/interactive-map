-- @copyright 2015-2017 City of Bloomington, Indiana
-- @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE.txt
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
    id               int unsigned not null primary key auto_increment,
    name             varchar(128) not null unique,
    alias            varchar(128) not null unique,
    description      varchar(128),
    internalFilename varchar(32)  not null,
    navigationMarkdown text,
    relatedMarkdown    text
);
