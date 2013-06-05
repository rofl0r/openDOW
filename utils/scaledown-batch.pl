#!/usr/bin/env perl
use strict;
use warnings;

use File::Basename;
use Cwd 'abs_path';
my $path = dirname(abs_path($0));

sub name_wo_ext {
        my $x = shift;
        my $l = length($x);
        $l-- while($l && substr($x, $l, 1) ne ".");
        return substr($x, 0, $l) if($l);
        return "";
}

sub file_ext {
        my $x = shift;
        my $l = length($x);
        $l-- while($l && substr($x, $l, 1) ne ".");
        return substr($x, $l) if($l);
        return "";
}

my $scale = shift @ARGV;
my $suffix = shift @ARGV;
die ("syntax: $0 downscalefactor suffix list-of-files") unless $scale =~ /^\d+$/ && defined($suffix);
for(@ARGV) {
	my $newfile = name_wo_ext($_) . $suffix . file_ext($_);
	my $cmd = $path . "/scaledown.out $scale $_ $newfile";
	print $cmd, "\n";
	system($cmd);
}
