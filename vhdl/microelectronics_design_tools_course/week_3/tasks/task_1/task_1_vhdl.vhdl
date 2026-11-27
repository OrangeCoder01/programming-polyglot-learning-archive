library ieee;
use ieee.std_logic_1164.all;


entity mux41 is
    port
    (
        x0: in std_logic;
        x1: in std_logic;
        x2: in std_logic;
        x3: in std_logic;

        y: out std_logic;

        sel: in std_logic_vector(1 downto 0)
    );
end entity mux41;

architecture ar_mux41 of mux41 is
    begin
        y <= x0 when sel = "00" then
             x1 when sel = "01" then
             x2 when sel = "10" then
             x3;
end architecture ar_mux41;