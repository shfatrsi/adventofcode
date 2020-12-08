#!/usr/bin/perl
use warnings;
use strict;

sub read {
    my $filename = 'input';
    open(FH, '<', $filename) or die $!;

    while(<FH>) {
        print $_;
    }
    close(FH);
}

sub showtime {
    print time;
    print "\n";
}

sub test {
    print "I am the text.\n";
}
