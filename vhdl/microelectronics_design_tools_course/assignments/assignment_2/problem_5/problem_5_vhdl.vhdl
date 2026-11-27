library ieee;
use ieee.std_logic_1164.all;

entity dec4to16 is
    port 
    (
        w  : in  std_logic_vector(3 downto 0);
        En : in  std_logic;
        y  : out std_logic_vector(0 to 15)
    );
end dec4to16;

architecture structural of dec4to16 is
    component dec2to4
        port 
        (
            w  : in  std_logic_vector(1 downto 0);
            En : in  std_logic;
            y  : out std_logic_vector(0 to 3)
        );
    end component;

    signal m : std_logic_vector(0 to 3);
begin
    -- First-stage decoder
    STAGE1: dec2to4 port map 
    (
        w  => w(3 downto 2),
        En => En,
        y  => m
    );

    -- Second-stage decoders
    STAGE2: for i in 0 to 3 generate
        DEC_i: dec2to4 port map 
        (
            w  => w(1 downto 0),
            En => m(i),
            y  => y(4*i to 4*i + 3)
        );
    end generate STAGE2;
end structural;