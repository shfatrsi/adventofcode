#!/usr/bin/perl
use warnings;
use strict;

sub read {
    my $filename = 'input';
    open(FH, '<', $filename) or die $!;

    my @lines;
    while(<FH>) {
        push(@lines, $_);
    }
    close(FH);
    return(@lines);
}

sub showtime {
    print time . "\n";
}

sub test {
    print "I am the text.\n";
}
