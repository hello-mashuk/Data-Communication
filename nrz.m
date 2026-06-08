%Lab Day 1 
%NRZ- non back to zero method in line decoding
%This code is an example of NRZI (Inversion)

bits = [1 0 1 1 1 0 0 1];
bitrate =1;
n=1000;
T=length(bits)/bitrate;
N=n*length(bits);
dt=T/N;
t=0:dt:T;
x=zeros(1,length(t));
lastbit=1;

for i=1: length(bits)
    if bits(i)==1
        x((i-1)*n+1:i*n)=-lastbit;
        lastbit=-lastbit;
    else
        x((i-1)*n+1:i*n)=lastbit;
    end
end
plot(t,x,'linewidth',3);
