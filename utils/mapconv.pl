#!/usr/bin/env perl
use strict;
use warnings;

print "\t.screens = {\n";
my $i = 0;
while(<>) {
	if(/^A/) {
		print "\t\t\t},\n\t\t},\n" if($i);
		print "\t\t[$i] = {\n\t\t\t.scrolldir = MS_UP,\n\t\t\t.bg = {\n";
		$i++;
		next;
	}
	if(/^B/) {
		print "\t\t\t},\n\t\t\t.fg = {\n";
		next;
	}
	next if(/^</ || /^>/);
	chomp;
	print "\t\t\t\t{$_},\n";
}
print "\t\t\t},\n\t\t},\n\t},\n";
