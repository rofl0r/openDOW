#!/usr/bin/env perl
use strict;
use warnings;

use File::Basename;
use Cwd 'abs_path';
my $path = dirname(abs_path($0));

my $inp = shift @ARGV or die ("$0 template-image series-of-images");
my $x = 99999999999;
my $y = 99999999999;
my $wmax = -1;
my $hmax = -1;
my $biggest = "";
for(@ARGV) {
	my $cmd = $path . "/imgdiff.out $inp $_ /tmp/__aaabbbbxxxx.png";
	my $res = `$cmd`;
	if($res =~ /(\d+),(\d+),(\d+),(\d+)/) {
		my $xi = $1;
		my $yi = $2;
		my $wi = $3;
		my $hi = $4;
		if($xi < $x) {
			$x = $xi;
			$biggest = $_;
		}
		if($yi < $y) {
			$y = $yi;
			$biggest = $_;
		}
		if($wi > $wmax) {
			$wmax = $wi;
			$biggest = $_;
		}
		if($hi > $hmax) {
			$hmax = $hi;
			$biggest = $_;
		}
	}
}

print "biggest: $biggest : $x,$y,$wmax,$hmax\n";
