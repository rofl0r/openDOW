#!/usr/bin/env perl
use strict;
use warnings;

use File::Basename;
use Cwd 'abs_path';
my $path = dirname(abs_path($0));
my $dim = shift @ARGV;
my $dimstr;

sub syntax {
	die("$0 -dim=x,y,w,h outfile%.2d.png blank-pic series-of-pics-to-be-diffed");
}

if ($dim =~ /-dim=(\d+),(\d+),(\d+),(\d+)/) {
} else {
	syntax();
}
my $name = shift @ARGV;
syntax() unless $name =~ /%.*d/;
my $inp = shift @ARGV;
my $x = 0;
for(@ARGV) {
	my $cmd = sprintf $path . "/imgdiff.out $dim $inp $_ $name", $x;
	my $res = `$cmd`;
	$x++;
}
