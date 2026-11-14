---
layout: blog-detil.cax
title: Choosing Between PaperHouse - Astro Bento Portfolio Template - Works, Blog, Docs, Order and Docus - Astro Starlight Docs Template - Documentation, Blog, Landing? Read This First
description: Technical comparison of PaperHouse Astro 7 bento portfolio template and Docus Astro Starlight documentation template for developers, studios, and agencies.
image: astro/astro-themes-paperhouse1_bdapzv.jpg
date: 2026-10-31
tags:
  - astro
  - astro-template
  - bento-portfolio
  - portfolio-template
  - docs-template
  - starlight
  - documentation-template
  - tailwind-template
---

## Introduction
Building a modern web presence requires picking the right template architecture aligned with your business model and content requirements. Astro has emerged as a premier framework for content-driven websites, offering zero-JavaScript defaults, fast page loads, and a flexible component architecture. When choosing an Astro template, developers and creators face a strategic decision: should you prioritize visually compelling portfolio showcases designed to convert client inquiries, or robust documentation systems designed to support technical software products?

This choice is highlighted when evaluating two prominent themes in the Astro ecosystem: [PaperHouse - Astro Bento Portfolio Template - Works, Blog, Docs, Order](/themes/astro/paperhouse-astro-themes/) and [Docus - Astro Starlight Docs Template - Documentation, Blog, Landing](/themes/astro/starlight-doc-astro-js/). While both templates utilize Astro to deliver rapid rendering and clean semantic HTML, their core architectures serve fundamentally different primary purposes. PaperHouse focuses on a bento-style portfolio layout powered by Astro 7 and Tailwind 4, aimed at studios, freelancers, and product creators who need to highlight past work, publish journal entries, and sell services via dedicated order pages. Conversely, Docus leverages the power of Astro Starlight to build full-scale technical documentation sites equipped with fast search, structured sidebars, MDX support, dark mode toggling, and product landing pages.

In this detailed evaluation, we will analyze the technical features, content workflows, visual design choices, and ideal deployment scenarios for both templates. By examining how each template manages content, styling, search engine optimization, and navigation, you will be equipped to select the right foundation for your next web project.

## Overview of PaperHouse - Astro Bento Portfolio Template - Works, Blog, Docs, Order
[PaperHouse - Astro Bento Portfolio Template - Works, Blog, Docs, Order](/themes/astro/paperhouse-astro-themes/) is engineered as a modern, aesthetic portfolio solution built on the latest Astro 7 and Tailwind 4 stacks. Designed around the popular bento-box grid aesthetic, PaperHouse allows agencies, design studios, and independent creators to showcase their output through structured visual modules. The theme embraces a distinct visual philosophy, focusing on clean typography, generous whitespace, subtle grain textures, and responsive layout structures that let content stand out without overwhelming the visitor.

Under the hood, PaperHouse implements a pure Markdown and JSON content pipeline that completely eliminates hardcoded layout elements. Content creators can update portfolio items, journal posts, documentation pages, and service offerings by modifying structured files rather than editing component markup. The template includes dedicated views for past works, a structured blog and journal, lightweight documentation pages, an about section, and a specialized order page tailored for direct client conversion. Its home page features interactive marquee banners alongside bento containers, giving creators a balanced mix of motion and static grid hierarchy. With a single $45 one-time price tag, PaperHouse provides full source code access without recurring subscription fees or complex external backend dependencies.

The site is built to handle single-person operations as well as multi-disciplinary creative studios. Because it leverages Tailwind 4 alongside Astro 7, customizing border radius values, color palettes, and typographic scales across the entire theme can be done through central style variables. Furthermore, per-page SEO controls ensure that individual portfolio pieces and blog entries rank effectively on search engines, making it a complete end-to-end publishing system for creative service providers.

## Overview of Docus - Astro Starlight Docs Template - Documentation, Blog, Landing
[Docus - Astro Starlight Docs Template - Documentation, Blog, Landing](/themes/astro/starlight-doc-astro-js/) is designed specifically for technical teams, software developers, and SaaS builders who need a comprehensive documentation infrastructure paired with marketing capabilities. Built on top of Astro Starlight, Docus combines deep technical documentation features—such as multi-level sidebar navigation, group index card views, instant keyboard-driven search (Ctrl+K), and dark/light mode toggling—with high-converting marketing assets like a product landing page and pricing matrix.

Docus uses MDX and JSON for content management, allowing developers to embed interactive components, custom callouts, code blocks, and rich media directly within standard Markdown documentation files. Beyond documentation, the template incorporates a fully featured blog complete with tag and category filtering, rendering it a dual-purpose engine for product user guides and technical content marketing. Developers retain 100% source code ownership with a one-time purchase of $65. This eliminates vendor lock-in while granting complete freedom to modify sidebars, custom static pages, contact forms, and component layouts.

The architectural focus of Docus is speed, structured readability, and technical scalability. Its integration with Astro Starlight guarantees strict adherence to web accessibility standards and performance metrics. Built-in search capabilities allow users to query full documentation archives without setting up complex third-party indexers, while automated SEO generation handles metadata across deep documentation trees automatically. Whether launching a new developer tool, an open-source library, or an enterprise SaaS platform, Docus supplies the necessary documentation and marketing infrastructure out of the box.

## Features Comparison

### Architecture and Framework Foundations
PaperHouse and Docus are built on distinct technical foundations optimized for different output goals. PaperHouse takes full advantage of Astro 7 paired with Tailwind 4. This pairing provides atomic utility CSS styling, small JavaScript bundle sizes, and modern layout primitives. Its rendering pipeline relies on standard Astro components and layouts, allowing developers familiar with basic HTML and Tailwind utility classes to quickly alter designs. 

In contrast, Docus builds directly on top of Astro Starlight, a specialized documentation framework integrated into Astro. Starlight provides specialized routing, built-in internationalization primitives, and robust layout structures tailored specifically for documentation libraries. While PaperHouse uses Tailwind 4 to drive utility styling across its bento components, Docus uses Starlight's theme engine supplemented by custom MDX rendering pipelines, enabling developer-friendly features like native dark, light, and automatic color scheme toggling right out of the box.

### Content Management and Data Workflow
Managing content across both templates relies on file-based workflows, but their execution reflects their primary target audiences. PaperHouse separates data management into pure Markdown files for long-form narrative content (such as blog posts, works, and doc articles) and JSON configuration files for structured data (such as hero section details, marquee text, and portfolio metadata). This zero-hardcode philosophy means non-technical users or content editors can modify portfolio items without touching layout code.

Docus elevates this workflow by implementing full MDX support alongside JSON data structures. MDX allows technical writers to insert dynamic Astro components, code blocks, interactive alerts, and visual cards directly into documentation and blog content. Furthermore, Docus includes structured JSON support for controlling doc sidebar trees, group index page cards, and blog tag/category taxonomies.

### Layout Aesthetics: Bento Grids vs Technical Sidebars
The visual hierarchy of these two themes targets completely different user experiences. PaperHouse utilizes a bento-box grid design language on its landing page and works showcase. Modules of varying aspect ratios combine to present text, imagery, tags, and animated marquee banners in a cohesive grid. This layout makes PaperHouse ideal for visual storytelling, brand showcases, and service sales where visual presentation is paramount.

On the other hand, Docus prioritizes quick information retrieval through a classic documentation layout. Its primary documentation interface features a fixed, multi-tiered sidebar for nested navigation, a centralized content pane, and an automatically generated table of contents on the right side. Docus also includes group index pages that automatically render child documentation sections as interactive cards, making navigation through extensive software manuals straightforward.

### Search, Navigation, and Discovery
Navigation mechanisms highlight the operational difference between a portfolio theme and a documentation engine. PaperHouse relies on clean top-level menu navigation (About, Docs, Works, Journal, Contact, Order) accompanied by category filtering within the works and journal sections. It focuses on guided visual exploration rather than targeted search across thousands of text pages.

Docus implements technical discovery tools essential for developer documentation. It features an integrated search modal accessible via the standard `Ctrl+K` keyboard shortcut, enabling users to search across all documentation pages and blog posts instantly. Furthermore, Docus includes built-in tag and category pages for its blog module, allowing readers to filter technical articles by specific topics or taxonomies.

### Conversion Elements and Commercial Features
Both themes recognize the need to drive commercial action, but they approach user conversion from different perspectives. PaperHouse includes a dedicated Order page alongside specialized pricing and service showcase cards within its bento system. Designed for agencies and freelancers selling fixed-price services or digital products, PaperHouse makes it easy for visitors to review work samples and immediately transition into a purchase or booking flow. It also includes an integrated contact form layout.

Docus approaches conversion from a software product perspective, featuring a dedicated landing page complete with hero banners, key feature grids, and a full Pricing page module. Additionally, Docus includes a flexible contact form structure aimed at capturing enterprise software inquiries, support tickets, or direct sales leads.

### SEO Optimization and Metadata Systems
PaperHouse handles search engine optimization through granular per-page metadata configuration. Content authors can specify custom titles, meta descriptions, social preview images (Open Graph graphs), and canonical URLs in the frontmatter of individual Markdown files or static Astro pages. This ensures that every portfolio case study or doc page can be optimized individually for search engine indexing and social sharing.

Docus relies on automated SEO handling powered by Astro Starlight's underlying architecture. Title tags, Open Graph meta tags, structured content schemas, and canonical links are generated automatically based on frontmatter entries and documentation folder hierarchies. Both approaches ensure high search engine visibility without requiring manual HTML head tag manipulation.

## Pricing
Pricing structures for both themes are transparent, one-time investments with no recurring SaaS subscription fees, user seat limits, or hidden maintenance costs. 

PaperHouse is available for a one-time purchase of $45. This includes complete source code access to the Astro 7 and Tailwind 4 template, allowing developers to host the site on any static hosting provider such as Cloudflare Pages, Vercel, or Netlify.

Docus is priced at $65 as a one-time fee. This price point reflects its additional complex infrastructure, including the integrated Astro Starlight engine, MDX component support, built-in search functionality, category-managed blog system, and product landing page layouts. Purchasers of Docus receive 100% source code ownership, allowing full freedom to customize, rebrand, and deploy without license restrictions.

## Who Should Choose PaperHouse - Astro Bento Portfolio Template - Works, Blog, Docs, Order
[PaperHouse - Astro Bento Portfolio Template - Works, Blog, Docs, Order](/themes/astro/paperhouse-astro-themes/) is tailored for individuals and creative businesses focused on personal branding, visual work presentation, and direct service conversion:

- **Design Studios & Digital Agencies:** Creative teams that need a modern bento portfolio to showcase client case studies, describe capabilities, and accept client inquiries through a structured order page.
- **Freelance Developers & Designers:** Independent professionals looking for a clean, typography-focused template to present their work history, publish technical journal articles, and sell specialized service packages.
- **Digital Product Creators:** Solopreneurs selling themes, micro-SaaS templates, or digital downloads who need a fast showcase landing page with marquee highlights and lightweight documentation.
- **Minimalist Content Creators:** Writers and educators who favor a clean visual aesthetic with subtle paper textures, quiet typography, and simple Markdown-driven workflows without heavy documentation sidebars.

## Who Should Choose Docus - Astro Starlight Docs Template - Documentation, Blog, Landing
[Docus - Astro Starlight Docs Template - Documentation, Blog, Landing](/themes/astro/starlight-doc-astro-js/) is designed for technical builders and software organizations requiring a comprehensive documentation system combined with product marketing tools:

- **Open-Source Software Maintainers:** Project leads who need an official documentation hub with fast search, MDX custom components, dark mode, and an integrated news/blog feed.
- **SaaS Developers & Startup Teams:** Software companies requiring a unified codebase that serves a marketing landing page, product pricing matrix, user documentation guides, and developer API references.
- **Developer Tool Creators:** Builders of CLI tools, APIs, software SDKs, or libraries who need multi-level sidebar navigation, keyboard shortcuts, and code-block capabilities.
- **Technical Documentation Teams:** Writers who manage large knowledge bases and require structured JSON sidebars, group index landing cards, and category/tag taxonomies to keep extensive documentation organized.

## Verdict
Selecting between PaperHouse and Docus comes down to identifying the primary objective of your site. If your primary goal is to present a visual portfolio, highlight creative work, publish thoughtful essays, and convert visitors into clients or purchasers of digital goods via an elegant bento grid, [PaperHouse - Astro Bento Portfolio Template - Works, Blog, Docs, Order](/themes/astro/paperhouse-astro-themes/) is the ideal choice. Its lightweight Astro 7 and Tailwind 4 architecture provides an aesthetic, fast, and easy-to-customize foundation at an accessible $45 price point.

On the flip side, if your main focus is building an extensive technical knowledge base, user manual, or software documentation portal alongside a marketing landing page and blog, [Docus - Astro Starlight Docs Template - Documentation, Blog, Landing](/themes/astro/starlight-doc-astro-js/) offers a far superior framework. By leveraging Astro Starlight, interactive search (Ctrl+K), MDX support, and automated doc sidebars, Docus delivers everything required to maintain complex software documentation at $65. Both templates offer complete source code ownership, zero hardcoding, and zero recurring fees, making either option a high-value investment for modern Astro developers.

## See It Live
Demo A: [PaperHouse - Astro Bento Portfolio Template - Works, Blog, Docs, Order](https://paperhouse-astro.pages.dev/)
Demo B: [Docus - Astro Starlight Docs Template - Documentation, Blog, Landing](https://astrodoc.pages.dev/)

## Related Themes
Explore more at [All Themes](https://www.hockeycomputindo.com/themes/) and [Premium Themes](https://www.hockeycomputindo.com/premium/).