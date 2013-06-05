#!/usr/bin/env perl
use strict;
use warnings;

use File::Basename;
use Cwd 'abs_path';
my $path = dirname(abs_path($0));
my $dim = shift @ARGV;
my $dimstr;
if ($dim =~ /-dim=(\d+),(\d+),(\d+),(\d+)/) {
} else {
	die("need -dim=x,y,w,h as first argv")
}
my $name = shift @ARGV;
die ("need name template containing %d as second argv") unless $name =~ /%.*d/;
my $inp = shift @ARGV;
my $x = 0;
for(@ARGV) {
	my $cmd = sprintf $path . "/imgdiff.out $dim $inp $_ $name", $x;
	my $res = `$cmd`;
	$x++;
}
