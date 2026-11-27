library ieee;
use ieee.std_logic_1164.all;

entity or2 is
    port
    (
        a, b: in std_logic;
        y: out std_logic
        );
        end entity or2;

architecture rtl of or2 is
    begin
        y <= a or b;
        end architecture rtl;

        


library ieee;
use ieee.std_logic_1164.all;

entity or3 is
    port
    (
        a,b,c: in std_logic;
        y: out std_logic
    );
end entity or3;

architecture structural of or3 is
    signal w: std_logic;
    component or2
        port
        (
            a, b: in std_logic;
            y: out std_logic
        );
    end component;
    begin
        U1 : or2 port map
            (
                a => a,
                b => b,
                y => 2
            )
        
        U2 : or2 port map
            (
                a => w,
                b => c,
                y => y
            );
end architecture structural;