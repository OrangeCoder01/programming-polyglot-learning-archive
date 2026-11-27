library ieee;
use ieee.std_logic_1164.all;

entity demux14 is
    port
    (
        x: in std_logic;
        sel: in std_logic_vector(1 downto 0);

        y0 : out std_logic;
        y1 : out std_logic;
        y2 : out std_logic;
        y3 : out std_logic
    );
end entity demux14;

architecture ar_demux41 of demux41 is
    begin
        y0 <= x when (sel = "00") else '0';
        y1 <= x when (sel = "01") else '0';
        y2 <= x when (sel = "10") else '0';
        y3 <= x when (sel = "11") else '0';
end architecture ar_demux41;
