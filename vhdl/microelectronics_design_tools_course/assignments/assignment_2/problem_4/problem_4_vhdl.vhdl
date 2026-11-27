library ieee;
use ieee.std_logic_1164.all;

entity mux4to1 is
    port 
    (
        w : in  std_logic_vector(0 to 3);
        s : in  std_logic_vector(1 downto 0);
        f : out std_logic
    );
end mux4to1;

architecture structural of mux4to1 is
    component dec2to4
        port 
        (
            w  : in  std_logic_vector(1 downto 0);
            En : in  std_logic;
            y  : out std_logic_vector(0 to 3)
        );
    end component;

    signal y : std_logic_vector(0 to 3);
begin
    U1: dec2to4 port map 
    (
        w  => s,
        En => '1',
        y  => y
    );

    f <= (w(0) and y(0)) or
         (w(1) and y(1)) or
         (w(2) and y(2)) or
         (w(3) and y(3));
end structural;