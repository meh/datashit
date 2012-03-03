require 'rake'
require 'rake/clean'

NAME    = 'datashit'
VERSION = '0.0.1'

def name
  "#{NAME}.#{VERSION}"
end

CC      = ENV['CC'] || 'clang'
AR      = ENV['AR'] || 'ar'
CFLAGS  = "-Os -Wall -Wextra -std=c99 -Iinclude" + " #{ENV['CFLAGS']}"
LDFLAGS = ENV['LDFLAGS']

if ENV['DEBUG']
  CFLAGS << ' -O0 -g3'
end

SOURCES = FileList['source/**/*.c']
OBJECTS = SOURCES.ext('o')

CLEAN.include(OBJECTS)
CLOBBER.include("lib#{name}.so", "lib#{name}-static.a")

task :default => ["lib#{name}.so", "lib#{name}-static.a"]

rule '.o' => '.c' do |t|
  sh "#{CC} #{CFLAGS} -fPIC -o #{t.name} -c #{t.source}"
end

file "lib#{name}.so" => OBJECTS do
  sh "#{CC} #{CFLAGS} #{OBJECTS} -shared -Wl,-soname,lib#{name} -o lib#{name}.so #{LDFLAGS}"
end

file "lib#{name}-static.a" => OBJECTS do
  sh "#{AR} rcs lib#{name}-static.a #{OBJECTS}"
end

task :examples => :default do
	%w(value count).each {|file|
		sh "#{CC} #{CFLAGS} examples/#{file}.c -o examples/#{file} -L. -static -l#{name}-static"
	}
end
