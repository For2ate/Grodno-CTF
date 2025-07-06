FROM ubuntu@sha256:899ec23064539c814a4dbbf98d4baf0e384e4394ebc8638bea7bbe4cb8ef4e12 as app

FROM pwn.red/jail

COPY --from=app / /srv

COPY ./ChattyParrot /srv/app/run

RUN chmod +x /srv/app/run


