APPNAME=maps

SASS := $(shell command -v pysassc 2> /dev/null)
MSGFMT := $(shell command -v msgfmt 2> /dev/null)

LANGUAGES := $(wildcard language/*/LC_MESSAGES)

default: clean compile package

deps:
ifndef SASS
	$(error "pysassc is not installed")
endif
ifndef MSGFMT
	$(error "msgfmt is not installed, please install gettext")
endif

clean:
	rm -Rf build
	mkdir build

	rm -Rf public/css/.sass-cache
	rm -Rf data/Themes/COB/public/css/.sass-cache

compile: deps $(LANGUAGES)
	cd public/css && pysassc -t compact -m screen.scss screen.css
	cd data/Themes/COB/public/css && pysassc -t compact -m screen.scss screen.css

package:
	rsync -rl --exclude-from=buildignore --delete . build/$(APPNAME)
	cd build && tar czf $(APPNAME).tar.gz $(APPNAME)

$(LANGUAGES): deps
	cd $@ && msgfmt -cv *.po
