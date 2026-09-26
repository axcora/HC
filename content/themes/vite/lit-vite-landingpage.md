---
layout: themes-detil.cax
title: Vite Lit Portfolio Landing Page website themes template
description: Free download and open source code vite lit Landing Page Portfolio website themes template for learn.
image: others/Vite_JS_Lit_Element_afrlg1.jpg
features:
 - Lit Element
 - Vite JS
 - Javascript Lang
 - JSON Data
 - Fast Website
 - Landing Page
 - Portfolio Section
 - Project Section
 - Web Features
 - Image Cover
 - All Modern static host support netlify, vercel, firebase and others.
 - All PHP Hosting support with build production mode Cpanel, Plesk, Direct Admin , VPS and others.
download: https://creativitaz.gumroad.com/l/vite-lit-portfolio
demo: https://www.hockeycomputindo.com/dokumentasi/
tags:
  - themestemplate
  - website themes
  - website template
  - vite
  - lit
  - podcast
  - themes
  - template
  - litthemes
  - vitethemes
  - jamstackthemes
  - freethemes
  - otherthemes
---


### Documentation

How to install and work with [Vite](https://vitejs.dev/) and [Lit](https://lit.dev/) project.

### Local Installation

+ Download and install [Node JS](https://nodejs.org/en/download/) on your devices
+ Download Source Code Project
+ Create New folder on desktop name it with your project.
+ Extract source code files in to your project 
+ Access with terminal run 'cd C:\Users\pcname\Desktop\yourproject' change pcname with your pc name and change yourproject with your new project.
+ Run Installation with Terminal `npm install && npm run dev`
+ Open localhost:5173
+ For stop , you can presh ctrl+C
+ For update article content access on `/src/` folder

### Setup Your Site Project

Now we need to update and change your website

#### Change Header Nav

For change header nav access on `src/my-nav.js` open with code editor

Next you can change and update the header nav section

Code

```
  constructor() {
    super();
    (this.title = 'This is your title header'),
    (this.description ='Description for your header'),
    (this.logo ='CDN Image logo in here...'),
    (this.url = 'Your site url'),
    (this.home = 'Your URL'),
    (this.info ='Your info text goes here..'),
    (this.condition = true);
  }
```

Implementation

```
  constructor() {
    super();
    (this.title = 'Creativitas Web Developer'),
    (this.description =
        'Built and Develope your site with modern technology JAMSTACK Static Site Generator + auto SEO injection'),
    (this.logo =
        'https://creativitas.github.io//assets/img/creativitaswebdev.webp'),
    (this.url = 'https://creativitas.dev'),
    (this.home = 'https://creativitas.dev'),
    (this.info =
        'Select your favorite technology 11ty Eleventy , Jekyll , Astro Js, React Js, Next Js, Gatsby Js , Svelte Kit, Angular , Pelican, Docusaurus, Mkdocs, Docfx, Sphinx , Starlight Js '),
    (this.condition = true);
  }
```

#### Change Intro Section 1

If you want to change intro section 1 , access on `src/dok/my-kasir.js` , open with code editor

And change this line code

```
  constructor() {
    super();
    (this.title = 'Your intro title here..'),
      (this.description = 'Your intro description here...'),
      (this.logo = 'URL CDN Image Logo'),
      (this.url = 'Site URL'),
      (this.pos = [
        {
          title: 'Card Title in here...',
          image: 'URL CDN Image Card here',
          info: 'Info text in here....',
          link: 'Link URL For this card here..',
          button: 'Button text in here...',
        },
      ]);
    this.condition = true;
  }
```

Implementation

```
  constructor() {
    super();
    (this.title = 'Modern JAMSTACK Website Developer'),
      (this.description =
        'Built your modern JAMSTACK site with creativitas.dev'),
      (this.logo =
        'https://creativitas.github.io//assets/img/creativitaswebdev.webp'),
      (this.url = 'https://creativitas.dev'),
      (this.pos = [
        {
          title: 'Welcome To My Site',
          image: 'https://creativebydre.github.io/assets/img/image.jpg',
          info: 'If you need develop your site, blog or documentation site project you can hire me now ',
          link: 'https://creativitas.dev/services/',
          button: 'Hire Me Now',
        },
      ]);
    this.condition = true;
  }
```

#### Change Intro Section 2

Next you can update your intro section 2 for example you want to display your services or portfolio , access on `src/dok/my-resto.js` open with code editor

And change this line code

```
  constructor() {
    super();
    (this.title = 'Your title for portfolio or services'),
      (this.description = 'Description for portfolio or Services'),
      (this.doclist = [
        {
          nav: 'List 1 title portfolio',
          image:'CDN IMage URL for List 1',
          info: 'Text information for list 1',
          link: 'URL Link for list 1',
        },
        {
          nav: 'List 2 title portfolio',
          image: 'CDN IMage URL for List 2',
          info: 'Text information for list 2',
          link: 'URL Link for list 2',
        },
        {
          nav: 'List 3 title portfolio',
          image: 'CDN IMage URL for List 3',
          info: 'Text information for list 3',
          link: 'URL Link for list 3',
        },
      ]);
    this.condition = true;
  }
```

Implementation

```
  constructor() {
    super();
    (this.title = 'Creativitas Services'),
      (this.description =
        'Website Blog and Documentation Site Developer Services'),
      (this.doclist = [
        {
          nav: 'Static Site Generator',
          image:'https://creativebydre.github.io/assets/img/image.jpg',
          info: 'Develop your jamstack sratic site generator 11ty jekyll astro js or python pelican',
          link: 'https://creativitas.dev/service/build-develop-website-with-jekyll-eleventy-astro-static-site-generator/',
        },
        {
          nav: 'React Website',
          image:'https://creativebydre.github.io/assets/img/image.jpg',
          info: 'Develop your website project with modern web react js, next js, gatsby js',
          link: 'https://creativitas.dev/service/react-website-blog-dev-next-gatsby-remix/',
        },
        {
          nav: 'Documentation Site',
          image:'https://creativebydre.github.io/assets/img/image.jpg',
          info: 'Develope your documentation website with docusaurus, starlight, mkdocs, sphinx, docfx',
          link: 'https://creativitas.dev/service/documentation-website-developer/',
        },
        {
          nav: 'PWA Website',
          image:'https://creativebydre.github.io/assets/img/image.jpg',
          info: 'Develop your modern PWA website with Svelte kit, Angular, Blazor WASM',
          link: 'https://creativitas.dev/service/modern-pwa-website-angular-svelte-blazor/',
        },
        {
          nav: 'Full SEO Website',
          image:'https://creativebydre.github.io/assets/img/image.jpg',
          info: 'Let build your custom website with full SEO injection script',
          link: 'https://creativitas.dev/service/custom-website-seo-developer/',
        },
      ]);
    this.condition = true;
  }
```

#### Change Intro Section 3

Next you can update your intro section 3 for example you want to display your project on this area , access on `src/dok/my-toko.js` open with code editor

And change this line code

```
  constructor() {
    super();
    (this.title = 'Your title for project'),
      (this.description = 'Description for project'),
      (this.doclist = [
        {
          nav: 'List 1 title project',
          image:'CDN IMage URL for List 1',
          info: 'Text information for list 1',
          link: 'URL Link for list 1',
        },
        {
          nav: 'List 2 title project',
          image: 'CDN IMage URL for List 2',
          info: 'Text information for list 2',
          link: 'URL Link for list 2',
        },
        {
          nav: 'List 3 title project',
          image: 'CDN IMage URL for List 3',
          info: 'Text information for list 3',
          link: 'URL Link for list 3',
        },
      ]);
    this.condition = true;
  }
```

Implementation

```
  constructor() {
    super();
    (this.title = 'Creativitas Web Themes'),
      (this.description = 'Awesome Themes Template by Creativitas'),
      (this.doclist = [
        {
          nav: 'BLACKS',
          image:'https://creativebydre.github.io/assets/img/image.jpg',
          info: 'Multipurpose Astro JS themes template',
          link: 'https://creativitas.dev/theme/astro-multipurpose/',
        },
        {
          nav: 'TEXT-X',
          image:'https://creativebydre.github.io/assets/img/image.jpg',
          info: 'Minimalist Clean Flatfile CMS themes template',
          link: 'https://creativitas.dev/theme/minimalist-clean-website-themes/',
        },
        {
          nav: 'DARKCO',
          image:'https://creativebydre.github.io/assets/img/image.jpg',
          info: 'New dark mode version flatfile CMS',
          link: 'https://creativitas.dev/theme/dark-new-modern-trend-website/',
        },
        {
          nav: 'RENT CAR',
          image:'https://creativebydre.github.io/assets/img/image.jpg',
          info: 'Built your modern rent car website with astro js + book form',
          link: 'https://creativitas.dev/theme/astro-rent-car/',
        },
        {
          nav: 'TAILWIND BLOG',
          image:'https://creativebydre.github.io/assets/img/image.jpg',
          info: 'Lets build your project with tailwind blog + backend admin flatfile cms',
          link: 'https://creativitas.dev/theme/tailwind-blog/',
        },
        {
          nav: 'MOBILE WEB',
          image:'https://creativebydre.github.io/assets/img/image.jpg',
          info: 'Get start now built mobile web with markdown PHP',
          link: 'https://creativitas.dev/theme/mobile-web-markdown-php/',
        },
      ]);
    this.condition = true;
  }
```

#### Change Footer Section

For change footer section access on `src/my-footer.js` and open with code editor

Update and Change on this line code

```
  constructor() {
    super();
    (this.title = 'This is your title footer'),
    (this.description ='Description for your footer'),
    (this.logo ='CDN Image logo in here...'),
    (this.url = 'Your site url'),
    (this.home = 'Your URL'),
    (this.info ='Your info text goes here..'),
    (this.condition = true);
  }
```

Implementation

```
  constructor() {
    super();
    (this.title = 'Creativitas Web Developer'),
    (this.description = 'Built and Develope your site with modern technology JAMSTACK Static Site Generator + auto SEO injection'),
    (this.logo = 'https://creativitas.github.io//assets/img/creativitaswebdev.webp'),
    (this.url = 'https://creativitas.dev'),
    (this.home = 'https://creativitas.dev'),
    (this.info = 'creativebydre@gmail.com'),
    (this.condition = true);
  }
```

#### Play Video

https://youtu.be/E-jttKMLMqE

#### Final Touch

Next you need to change title, description for meta tag, open graph and twitter card, access in to `index.html` file, and change title description with your site title and description, and save it.


### Deploy To Hosting [vite lit themes template]({{page.url}})

How to deploy in to your host ?? Create github repo , and push your source code project.

#### Netlify Deploy

+ Register on netlify with your github account
+ Create New project
+ Integrate your github repo project
+ Select your vite lit portfolio repo
+ Deploy your project
+ Select Framework None / Other
+ Build Command `npm run build`
+ Output folder `dist`

#### Vercel Deploy

+ Register on vercel with your github account
+ Create New project
+ Integrate your github repo project
+ Select your vite lit portfolio repo
+ Deploy your project
+ Select Framework None / Other
+ Build Command `npm run build`
+ Output folder `dist`

#### Cloudflare Deploy

+ Register on Cloudflare
+ Click on Pages /Worker - Select Pages
+ Create New Cloudflare Pages
+ Integrate your github repo project
+ Select your vite lit portfolio repo
+ Deploy your project
+ Select Framework None / Other
+ Build Command `npm run build`
+ Output folder `dist`

#### Firebase Deploy

+ Register on Firebase
+ Run Firebase CLI command
+ Build your project with `npm run build`
+ Access on production folder `dist`
+ Configuration your `dist` folder with firebase project
+ Push your `dist` folder in to firebase host

#### PHP Hosting & Others Deploy

+ Run production for your website project with `npm run build`
+ Login in to your Hosting Panel
+ Upload the production folder `dist` in to your project

### Thank You by using [vite lit themes template]({{page.url}}) project

We hope with this source code ,you can learn about vite and lit.
