#!/usr/bin/env perl
use strict;
use warnings;

print "\t.screens = {\n";
my $i = 0;
my $bonus_active = 0;
my %bonus;
my $bonus_num = 0;
while(<>) {
	if(/^A/) {
		$bonus_active = 0;
		print "\t\t\t}},\n\t\t},\n" if($i);
		print "\t\t[$i] = {\n\t\t\t.bg = {{\n";
		$i++;
		next;
	}
	if(/^B/) {
		$bonus_active = 0;
		print "\t\t\t}},\n\t\t\t.fg = {{\n";
		next;
	}
	if(/^C/) {
		$bonus_active = 1;
		$bonus_num = $i - 1;
		next;
	}
	$bonus_active = 0, next if(/^</ || /^>/);
	if($bonus_active) {
		$bonus{$i - 1} = defined($bonus{$i - 1}) ? $bonus{$i - 1} . $_ : $_;
		next;
	}
	chomp;
	print "\t\t\t\t{$_},\n";
}
print "\t\t\t}},\n\t\t},\n\t},\n";
for(keys(%bonus)) {
	print("bonus for $_\n");
	my @lines = split /\n/, $bonus{$_};
	print "{$_},\n" for(@lines);
}
