% mancester encoding
%example input = [1 0 0 1 0]

bits = input('prompt');
bitrate =1;
n=1000;
T=length(bits)/bitrate;
N=n*length(bits);
dt=T/N;
t=0:dt:T;
x=zeros(1,length(t));


for i=1: length(bits)
    if bits(i)==1
        x((i-1)*n+1:(i-1)*n)=1;
        x((i-1)*n+n/2:i*n)=-1;
        
    else
        x((i-1)*n+1:(i-1)*n)=-1;
        x((i-1)*n+n/2:i*n)=-1;
    end
end
plot(t,x,'linewidth',3);
