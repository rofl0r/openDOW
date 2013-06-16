#!/usr/bin/env perl
use strict;
use warnings;

print "\t.screens = {\n";
my $i = 0;
my $bonus_active = 0;
my @bonus = ();
my $bonus_num = 0;
while(<>) {
	if(/^A/) {
		$bonus_active = 0;
		print "\t\t\t},\n\t\t},\n" if($i);
		print "\t\t[$i] = {\n\t\t\t.scrolldir = MS_UP,\n\t\t\t.bg = {\n";
		$i++;
		next;
	}
	if(/^B/) {
		$bonus_active = 0;
		print "\t\t\t},\n\t\t\t.fg = {\n";
		next;
	}
	if(/^C/) {
		$bonus_active = 1;
		$bonus_num = $i - 1;
		next;
	}
	next if(/^</ || /^>/);
	chomp;
	if($bonus_active) {
		push @bonus, $_;
		next;
	}
	print "\t\t\t\t{$_},\n";
}
print "\t\t\t},\n\t\t},\n\t},\n";
if(scalar(@bonus)) {
	print("bonus for $bonus_num\n");
	print "{$_},\n" for(@bonus);
}
